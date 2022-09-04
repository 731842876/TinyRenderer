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

        if (!lineContent.compare(0, 2, "v ")) {
            // 将每行多余的内容去掉
            iss >> buf;

            Vec3f p;
            for (int i = 0; i < 3; i++) {
                iss >> p.raw[i];
            }
            _vecVertex.push_back(p);

        } else if (!lineContent.compare(0, 2, "f ")) {
            std::vector<int> f;
            int index, ibuf;
            iss >> buf;

            while (iss >> index >> buf >> ibuf >> buf >> ibuf) {
                index--;
                f.push_back(index);
            }
            _vecFace.push_back(f);
        }
    }
    std::cout << " Vertx Size->" << _vecVertex.size() << std::endl;
    std::cout << " Faces Size->" << _vecFace.size() << std::endl;
}
Model::~Model() {}

int Model::VertexSize() {
    return _vecVertex.size();
}
int Model::FacesSize() {
    return _vecFace.size();
}

Vec3f Model::GetVertex(int index) {
    return _vecVertex[index];
}

std::vector<int> Model::GetFace(int index) {
    return _vecFace[index];
}
