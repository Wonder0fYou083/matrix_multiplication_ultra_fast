#include "mat.h"
#include <stddef.h>
#include <stdio.h>

void mat_fun(Mat m, float f(void)) {
    for (size_t i = 0; i < m.rows * m.cols; ++i) {
        m.data[i] = f();
    }
}

void mat_mul(Mat c, Mat a, Mat b) {
    for (size_t i = 0; i < c.rows; ++i) {
        for (size_t j = 0; j < c.cols; ++j) {
            uint32_t c_ix = i * c.cols + j;
            c.data[c_ix] = 0.0f;
            for (size_t k = 0; k < a.cols; ++k) {
                c.data[c_ix] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
            }
        }
    }
}

void mat_print(Mat m) {
    for (size_t i = 0; i < m.rows; ++i) {
        for (size_t j = 0; j < m.cols; ++j) {
            printf(" %6.2f", m.data[i * m.cols + j]);
        }
        printf("\n");
    }
}