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

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

using namespace std;

int main() {
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
            DrawLine_V4(x0, y0, x1, y1, image, white);
        }
    }

    image.flip_vertically();  // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");

    return 0;
}