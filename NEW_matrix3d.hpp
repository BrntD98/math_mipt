/*
 /*
 * matrix3d.h
 *
 *  Created on: 13 февр. 2023 г.
 *      Author: alina
 */

#ifndef MATRIX3D_H_
#define MATRIX3D_H_

#include <iostream>
#include <utility>
#include<vector>
#include<array>

template<typename T>
struct elements{
	T a; //верхняя побочная диагональ
	T b; //главная диагональ 
	T c; //нижняя побочная диагональ
};


template<typename T>
class matrix3d{
private:
	std::vector<elements<T>> M;
public:
	matrix3d(const std::vector<elements<T>> &v){
	M=v;

	}

	~matrix3d()=default;
	const T operator()(unsigned long long int i, unsigned long long int j) const {

			if (j==0)
				return M[i].a;
			if (j==1)
				return M[i].b;
			if (j==2)
				return M[i].c;

	}
	unsigned long long int size() const {
		return M.size();
	}

};

#endif
