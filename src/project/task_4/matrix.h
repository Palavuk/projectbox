#pragma once
#include <vector>
#include <cmath>

double eps = 1e-6;

template <class T>
class matrix{
    private:
        std::vector<T> data;
        size_t str;
        size_t clmn;
    public:
        matrix() : data(){
            str = 0;
            clmn = 0;
        };

        matrix(size_t _str, size_t _clmn) : data(_str * _clmn){
            str = _str;
            clmn = _clmn;
        };

        matrix(const std::vector<T>& _data, size_t _str, size_t _clmn) : data(_data){
            str = _str;
            clmn = _clmn;
        };

        matrix(const matrix<T>& mtrx) : data(mtrx.data){
            str = mtrx.str;
            clmn = mtrx.clmn;
        };

	    matrix(matrix<T>&& mtrx) : data(std::move(mtrx.data)){
            str = std::move(mtrx.str);
            clmn = std::move(mtrx.clmn);
        };

        matrix<T>& operator=(const matrix<T>& mtrx)
	    {
	    	if (this == &mtrx)
	    		return *this;
	    	data = mtrx.data;
	    	str = mtrx.str;
	    	clmn = mtrx.clmn;
	    	return *this;
	    };

	    matrix<T>& operator=(matrix<T>&& mtrx)
	    {
	    	if (this == &mtrx)
	    		return *this;
	    	data = std::move(mtrx.data);
	    	str = std::move(mtrx.str);
	    	clmn = std::move(mtrx.clmn);
	    	return *this;
	    };

	    matrix<bool> operator>(const matrix<T>& mtrx)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < mtrx.data.size(); i++)
	    	{
	    		result[i] = data[i] > mtrx.data[i];
	    	}
	    	return result;
	    };

	    matrix<bool> operator<(const matrix<T> mtrx)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < mtrx.size(); i++)
	    	{
	    		result[i] = data[i] < mtrx.data[i];
	    	}
	    	return result;
	    };

	    matrix<bool> operator>=(const matrix<T>& mtrx)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < mtrx.size(); i++)
	    	{
	    		result[i] = data[i] >= mtrx.data[i];
	    	}
	    	return result;
	    };

	    matrix<bool> operator<=(const matrix<T>& mtrx)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < mtrx.size(); i++)
	    	{
	    		result[i] = data[i] <= mtrx.data[i];
	    	}
	    	return result;
	    };

        matrix<bool>& operator==(const T& n)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < data.size(); i++)
	    	{
	    		result[i] = data[i] == n;
	    	}
	    	return result;
	    };

        matrix<bool> operator<(const T& n)
	    {
	    	matrix<bool> result(str, clmn);
	    	for (size_t i = 0; i < result.size(); i++)
	    	{
	    		result[i] = data[i] < n;
	    	}
	    	return result;
	    };

        matrix<T> transposed(){
            matrix<T> result(clmn, str);
            for (size_t i = 0; i < str; i++)
                for (size_t j = 0; j < clmn; j++)
                    result.data[j * str + i] = data[(i) * clmn + j];
        };

        bool is_symmetric(){
            matrix<T> mtrx(data, str, clmn);
            return all(abs(*this - mtrx.transposed()) < eps);
        }

        T& operator[](size_t i){ return data[i]; };

        T operator[](size_t i) const { return data[i]; };

        size_t size() const {return clmn * str;};
        size_t _str() const {return str;};
        size_t _clmn() const {return clmn;};
};

template<class T>
bool operator==(const matrix<T>& lhs, const matrix<T>& rhs)
{
	for (int i = 0; i < lhs.size(); i++)
	{
		if (lhs[i] != rhs[i])
			return false;
	}

	return true;
}

template<class T>
matrix<T> abs(const matrix<T>& mtrx)
{
	matrix<T> result;
	for (size_t i = 0; i < mtrx.size(); i++)
	{
		result[i] = std::abs(mtrx[i]);
	}
	return result;
};

bool all(const matrix<bool>& mtrx)
{
	matrix<bool> result(mtrx._str(), mtrx._clmn());
	for (size_t i = 0; i < mtrx.size(); i++)
	{
		if (!mtrx[i])
			return false;
	}
	return true;
}

template<class T>
matrix<T> operator-(const matrix<T>& mtrxl, const matrix<T>& mtrxr)
{
	matrix<T> result(mtrxl);
	for (size_t i = 0; i < result.size(); i++)
	{
		result[i] = mtrxl[i] - mtrxr[i];
	}
	return result;
}

template<class T>
matrix<T> where(const matrix<bool>& bool_matr, const matrix<T>& mtrxl, const matrix<T>& mtrxr)
{
	matrix<T> result(mtrxl._str(), mtrxr._clmn());
	for (int i = 0; i < result.size(); i++)
	{
		result[i] = bool_matr[i] ? mtrxl[i] : mtrxr[i];
	}
	return result;
}
