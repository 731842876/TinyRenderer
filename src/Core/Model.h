/*
 * @Author: qianwanyu 731842876@qq.com
 * @Date: 2022-08-19 16:05:26
 * @Description:
 *
 * Copyright (c) 2022 by qianwanyu 731842876@qq.com, All Rights Reserved.
 */

#ifndef Model_H
#define Model_H

#include <vector>

#include "Geometry.h"

class Model {
private:
    //每个顶点xyz坐标
    std::vector<Vec3f> _vecVertex;
    //每个面所需的三个点
    std::vector<std::vector<int>> _vecFace;

public:
    explicit Model(const char* fileName);
    ~Model();

    int VertexSize();
    int FacesSize();
    Vec3f GetVertex(int index);
    std::vector<int> GetFace(int index);
};

#endif
