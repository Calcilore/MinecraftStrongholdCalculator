#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double torad(double deg) {
    return deg / 360.0 * (2.0 * M_PI);
}

int main(int argc, char** argv) {
    if (argc <= 21) {
        // char line[256];
        // printf("F3+C output 1: ");
        // if (fgets(line, sizeof(line), stdin)) {
        //     // remove trailing newline if present
        //     line[strcspn(line, "\n")] = '\0';
        //
        //     char *token = strtok(line, " ");
        //     for (int i = 0; token != NULL; ++i) {
        //         printf("Token %d: %s\n", i, token);
        //         token = strtok(NULL, " ");
        //     }
        // }
        printf("NO ARGS!!!!\n");
        return 1;
    }

    double p1x = atof(argv[7]);
    double p1y = atof(argv[9]);
    double m1 = atof(argv[10]);
    double p2x = atof(argv[18]);
    double p2y = atof(argv[20]);
    double m2 = atof(argv[21]);

    // printf("%f %f %f %f %f %f\n", p1x, p1y, m1, p2x, p2y, m2);

    double af = torad(fmod(90 + fmod(m1 + 360.0, 360.0), 360.0));
    double bf = torad(fmod(90 + fmod(m2 + 360.0, 360.0), 360.0));

    // printf("%f %f\n", af, bf);
    
    double p12x = p1x + 50 * cos(af);
    double p12y = p1y + 50 * sin(af);

    // printf("%f %f\n", p12x, p12y);

    double p22x = p2x + 50 * cos(bf);
    double p22y = p2y + 50 * sin(bf);

    // printf("%f %f\n", p22x, p22y);

    double g1 = (p1y - p12y) / (p1x - p12x);
    double g2 = (p2y - p22y) / (p2x - p22x);

    // printf("%f %f\n", g1, g1);

    double xs = (g1 * p1x - g2 * p2x - p1y + p2y) / (g1 - g2);
    double ys = g1 * (xs - p1x) + p1y;

    printf("Overworld: %0.1f %0.1f\n", xs, ys);
    printf("Nether:    %0.1f %0.1f\n", xs / 8.0, ys / 8.0);

    return 0;
}

