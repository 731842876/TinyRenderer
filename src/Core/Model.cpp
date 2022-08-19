/*
 * @Author: qianwanyu 731842876@qq.com
 * @Date: 2022-08-19 16:10:15
 * @Description:
 *
 * Copyright (c) 2022 by qianwanyu 731842876@qq.com, All Rights Reserved.
 */

#include "Model.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Model::Model(const char* fileName) {
    std::ifstream in;
    in.open(fileName, std::ifstream::in);
    if (in.fail()) {
        return;
    }

    std::string lineContent;

    while (!in.eof()) {
        std::getline(in, lineContent);
        std::istringstream iss(lineContent.c_str());

        char buf;
        if (lineContent.compare(0, 2, "v ")) {
            iss >> buf;
            Vec3f v;
            for (int i = 0; i < 3; i++) {
                iss >> v.raw[i];
            }
            _vec3f.push_back(v);

        } else if (lineContent.compare(0, 2, "f ")) {
            // std::vector<int> f;
            // int buf, index;
            // iss >> trash;
            // while (iss >> idx >> trash >> itrash >> trash >> itrash) {
            //     idx--;  // in wavefront obj all indices start at 1, not zero
            //     f.push_back(idx);
            // }
            // _vecFaces.push_back(f);
        }
    }
}

Model::~Model() {}

int Model::VertsSize() {
    return _vec3f.size();
}
int Model::FacesSize() {
    return _vecFaces.size();
}

Vec3f Model::Vert(int index) {
    return _vec3f[index];
}

std::vector<int> Model::Faces(int index) {
    return _vecFaces[index];
}
