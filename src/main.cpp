/*
 * @Author: qianwanyu 731842876@qq.com
 * @Date: 2022-08-18 14:27:34
 * @Description:
 *
 * Copyright (c) 2022 by qianwanyu 731842876@qq.com, All Rights Reserved.
 */

#include <iostream>
#include <sstream>
#include <vector>

#include "Core/DrawLine.h"
#include "Core/Model.h"

const TGAColor green = TGAColor(160, 191, 124, 255);
const TGAColor red = TGAColor(248, 147, 29, 255);
const TGAColor blue = TGAColor(147, 224, 255, 255);

using namespace std;

struct Triangle {
    Vec2i Points[3];

    Triangle(Vec2i a, Vec2i b, Vec2i c) {
        Points[0] = a;
        Points[1] = b;
        Points[2] = c;
    }
};

void s1() {
    // 点绘制
    // TGAImage image(100, 100, TGAImage::RGB);
    // image.set(52, 41, white);

    // 线条绘制
    // vector<vector<int>> PosValue = {{13, 20, 80, 40}, {20, 13, 30, 90}, {80, 40, 13, 20}};
    // vector<TGAColor> colors = {white, red, blue};
    // TGAImage image(100, 100, TGAImage::RGB);
    // int i=0;
    // for (auto& values : PosValue) {
    //     DrawLine_V4(values[0], values[1], values[2], values[3], image, colors[i++]);
    // }

    // 读取模型并绘制
    TGAImage image(800, 800, TGAImage::RGB);
    Model m("../obj/head.obj");
    for (int i = 0; i < m.FacesSize(); i++) {
        vector<int> face = m.GetFace(i);

        for (int j = 0; j < 3; j++) {
            Vec3f v0 = m.GetVertex(face[j]);
            Vec3f v1 = m.GetVertex(face[(j + 1) % 3]);

            int x0 = (v0.x + 1.) * 800 / 2.;
            int y0 = (v0.y + 1.) * 800 / 2.;
            int x1 = (v1.x + 1.) * 800 / 2.;
            int y1 = (v1.y + 1.) * 800 / 2.;
            DrawLine_V4(x0, y0, x1, y1, image, green);
        }
    }

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return;
}

// 射线法
void TriangleDrawing(Triangle triangle, TGAImage& res) {
    Vec2i a = triangle.Points[0];
    Vec2i b = triangle.Points[1];
    Vec2i c = triangle.Points[2];

    // 根据Y轴从小到大排序三个点
    if (a.y > b.y) {
        swap(a, b);
    }
    if (a.y > c.y) {
        swap(a, c);
    }
    if (b.y > c.y) {
        swap(b, c);
    }

    // 整体
    int h1 = c.y - a.y;
    // 上半部分
    int h2 = c.y - b.y;
    // 下半部分
    int h3 = b.y - a.y;

    for (int h = 0; h <= h1; h++) {
        // 从下到上绘制，判断是否到达上半部分
        bool otherHalf = h >= h3 || b.y == a.y;

        int height = otherHalf ? h2 : h3;

        // 左边界比例
        float leftBeta = (float)h / h1;
        // 右边界
        float rightBeta = (float)(h - (otherHalf ? h3 : 0)) / height;

        Vec2i start = a + (c - a) * leftBeta;
        Vec2i end = otherHalf ? b + (c - b) * rightBeta : a + (b - a) * rightBeta;

        for (int i = start.x; i <= end.x; i++) {
            res.set(i, a.y + h, green);
        }
    }
}

void s2() {
    TGAImage image(400, 400, TGAImage::RGB);

    // vector<vector<Vec2i>> Triangles = {{{200, 200}, {300, 100}, {70, 80}}};
    Triangle t({200, 200}, {300, 100}, {70, 80});
    TriangleDrawing(t, image);

    image.flip_vertically();
    image.write_tga_file("output.tga");

    return;
}

int main() {
    s2();
}