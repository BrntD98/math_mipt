
#include "matrix3d.h"


template <typename T>
	T matrix3d<T>::operator()(unsigned int i; int j){
		if (i==j)
			return M[i].a;
		if (i==j+1)
			return M[i].b;
		if (i==j-1)
			return M[i].c;
}

