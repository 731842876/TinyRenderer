/*
 * @Author: qianwanyu 731842876@qq.com
 * @Date: 2022-08-18 14:27:34
 * @Description:
 *
 * Copyright (c) 2022 by qianwanyu 731842876@qq.com, All Rights Reserved.
 */

#include <iostream>
#include <vector>

#include "Core/DrawLine.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

using namespace std;

int main() {
    vector<vector<int>> PosValue = {{13, 20, 80, 40}, {20, 13, 30, 90}, {80, 40, 13, 20}};
    vector<TGAColor> colors = {white, red, blue};
    TGAImage image(100, 100, TGAImage::RGB);
    int i=0;
    for (auto& values : PosValue) {
        DrawLine_V3(values[0], values[1], values[2], values[3], image, colors[i++]);
    }

    image.flip_vertically();  // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");

    return 0;
}