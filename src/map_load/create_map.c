/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-louis.rollet
** File description:
** create_map
*/

#include "my.h"

double noise(int x, int y, int seed)
{
    int n = x + y * 57 + seed;
    n = (n << 13) ^ n;
    return (1.0 - ((n * (n * n * 15731 + 789221) +
    1376312589) & 0x7fffffff) / 1073741824.0);
}

double smoothnoise(double x, double y, int seed)
{
    double corners = (noise(x - 1, y - 1, seed) +
    noise(x + 1, y - 1, seed) + noise(x - 1, y + 1, seed) +
    noise(x + 1, y + 1, seed)) / 16;
    double sides = (noise(x - 1, y, seed) + noise(x + 1, y, seed) +
    noise(x, y - 1, seed) + noise(x, y + 1, seed)) / 8;
    double center = noise(x, y, seed) / 4;
    return corners + sides + center;
}

double interpolate(double a, double b, double x)
{
    double ft = x * M_PI;
    double f = (1 - cos(ft)) * .5;
    return a * (1 - f) + b * f;
}

double interpolatedoise(double x, double y, int seed)
{
    int integerX = (int)x;
    double fractionalX = x - integerX;

    int integerY = (int)y;
    double fractionalY = y - integerY;

    double v1 = smoothnoise(integerX, integerY, seed);
    double v2 = smoothnoise(integerX + 1, integerY, seed);
    double v3 = smoothnoise(integerX, integerY + 1, seed);
    double v4 = smoothnoise(integerX + 1, integerY + 1, seed);

    double i1 = interpolate(v1 , v2 , fractionalX);
    double i2 = interpolate(v3 , v4 , fractionalX);

    return interpolate(i1 , i2 , fractionalY);
}

double perlinnoise(double x, double y, int seed)
{
    double total = 0;
    double p = PERSISTENCE;
    int n = OCTAVES;

    for (int i = 0; i < n; i++) {
        double frequency = pow(2,i);
        double amplitude = pow(p,i);

        total += interpolatedoise(x * frequency *
        NOISE_SCALE, y * frequency * NOISE_SCALE,
        seed) * amplitude;
    }

    return total;
}
