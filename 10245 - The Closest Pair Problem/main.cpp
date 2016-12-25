#include<bits/stdc++.h>
using namespace std;
int main() {

    int i, j, N;
    double min_distance, distance, x[10000], y[10000];

    while (scanf("%d", &N) == 1 && N) {

        min_distance = 100000000;

        for (i = 0; i < N; i++)
            scanf("%lf %lf", &x[i], &y[i]);

        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++) {
                distance = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]);
                if (min_distance > distance)
                    min_distance = distance;
            }

        min_distance = sqrt(min_distance);

        if (min_distance < 10000)
            printf("%.4lf\n", min_distance);
        else
            printf("INFINITY\n");
    }
    return 0;
}
