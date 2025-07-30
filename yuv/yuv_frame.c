/*

y = Brightness channel
u = Blue channel
v = Red channel

*/

#include <stdio.h>
#include <stdint.h>

#define WIDTH 4
#define HEIGHT 4
#define FRAME 30

int main(int argc, char **argv)
{

    char *yuv_file_name = "animated.yuv";

    if (remove(yuv_file_name) == 0)
    {
        printf("%s is deleted.\n", yuv_file_name);
    }
    else
    {
        fprintf(stderr, "Couldn't delete the file: %s.", yuv_file_name);
    }

    FILE *fp = fopen(yuv_file_name, "wb");

    if (!fp)
    {
        perror("Cannot open output file");
        return 1;
    }

    // === U PLANE === (2x2 = 4 bytes)
    uint8_t u_plane[(WIDTH / 2) * (HEIGHT / 2)] = {
        128, 140,
        120, 135};

    // === V PLANE === (2x2 = 4 bytes)
    uint8_t v_plane[(WIDTH / 2) * (HEIGHT / 2)] = {
        128, 120,
        135, 140};

    for (int frame = 0; frame < FRAME; frame++)
    {

        uint8_t brightness = (frame * 8) % 256;

        uint8_t y_plane[WIDTH * HEIGHT];

        for (int i = 0; i < WIDTH * HEIGHT; i++)
            y_plane[frame] = brightness;

        printf("Sizeof: %zu\n", sizeof(y_plane));
        printf("Sizeof: %zu\n", sizeof(u_plane));
        printf("Sizeof: %zu\n", sizeof(v_plane));

        fwrite(y_plane, 1, sizeof(y_plane), fp);
        fwrite(u_plane, 1, sizeof(u_plane), fp);
        fwrite(v_plane, 1, sizeof(v_plane), fp);

        printf("Wrote frame %d with brightness %d\n\n", frame, brightness);
    }

    fclose(fp);

    printf("✅ YUV frame written to %s\n", yuv_file_name);

    return 0;
}