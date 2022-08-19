/*
 * @Author: qianwanyu 731842876@qq.com
 * @Date: 2022-08-18 15:26:24
 * @Description: Bresenham’s Line Drawing Algorithm
 *
 * Copyright (c) 2022 by qianwanyu 731842876@qq.com, All Rights Reserved.
 */

#include "Core/tgaimage.h"

//简单线性插值，t的取值从0到1
void DrawLine_V1(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor color) {
    for (float t = 0.; t < 1.; t += .01) {
        int x = (x1 - x0) * t + x0;
        int y = (y1 - y0) * t + y0;
        img.set(x, y, color);
    }
}

//直接采取x0到x1位移方向的值作为采样率
//当初始值x1>=x0时，无法绘制
//当初始值x0到x1的的值作为步长远小于 y0到y1时绘制绘图存在空隙或者较短
void DrawLine_V2(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor color) {
    for (int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float)(y1 - y0);
        int y = (y1 - y0) * t + y0;
        img.set(x, y, color);
    }
}

void DrawLine_V3(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor color) {
    bool steep = false;
    if (std::abs(x1 - x0) < std::abs(y1 - y0)) {
        // 解决最大位移方向为y轴
        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    if (x0 >= x1) {
        //解决初始值x1>=x0
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for (int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float)(x1 - x0);
        int y = (y1 - y0) * t + y0;
        // int y = y1 + (1 - t) * y0;
        if (steep) {
            img.set(y, x, color);
        } else {
            img.set(x, y, color);
        }
    }
}

//优化 将循环中的float除法 改为 循环外计算
void DrawLine_V4(int x0, int y0, int x1, int y1, TGAImage& img, TGAColor color) {
    bool steep = false;
    if (std::abs(x1 - x0) < std::abs(y1 - y0)) {
        // 解决最大位移方向为y轴
        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    if (x0 >= x1) {
        //解决初始值x1>=x0
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dy = y1 - y0;
    int dx = x1 - x0;
    //直线斜率 k=dy/dx
    float k = std::abs(dy / (float)dx);
    float err = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (steep) {
            img.set(y, x, color);
        } else {
            img.set(x, y, color);
        }
        err += k;
        if (err >= .5) {
            // y轴从高到低
            y += (y1 > y0) ? 1 : -1;
            err -= 1.;
        }
    }
}
