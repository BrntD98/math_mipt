#include "NEW_matrix3d.hpp"

template<typename T>
std::vector<T> progonka(const matrix3d<T> &M, const std::vector<T>& f) {

	unsigned long long int n=M.size();
	std::vector<T> x(n);
	std::vector<T> y(n);
	std::vector<T> z(n);

	 x[0] = -M(0,2) / M(0,1);
	 y[0] = -f[0] /  M(0,1) ;


	  for (unsigned long long int i = 0; i < n; i++) {
	   x[i+1] = -M(i,2) / (M(i,0) * x[i] + M(i,1));
	   y[i+1] = (f[i] - (M(i,0)*y[i]))/(M(i,0)*x[i]+M(i,1));}

	  z[n-1]=(f[n-1]-(M(n-1,0)*y[n-1]))/(M(n-1,0)*x[n-1]+M(n-1,1));

	  for(unsigned long long int i = n-1; i-- > 0; i){
	         z[i] = z[i+1]*x[i+1] + y[i+1];
	     }
	     return z;


}
