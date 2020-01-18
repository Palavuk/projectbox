#include <cstring>
#include <iostream>
#include <cstring>
#include <array>
#include <functional>
#include <vector>

template <class strm, class T>
void message(strm& stream, const char* format, T arg) {
	int count = strlen(format);
	for (int i = 0; i < count; i++)
		if (format[i] != '%')
			stream << format[i];
		else
		{
			stream << arg;
			if (i < count - 2)
				stream << &format[i + 1];
			break;
		}
}

template <class strm, class Type, class ... T>
void message(strm& stream, const char* format, Type arg, T ... args) {
	int count = strlen(format);
	for (int i = 0; i < count; i++)
		if (format[i] != '%')
			stream << format[i];
		else {
			stream << arg;
			message(stream, &format[i + 1], args...);
			break;
		}

}

template <class T, std::size_t n>
std::array<T, 2 * n> cat(std::array<T, n> arr1, std::array<T, n> arr2) {
	std::array<T, 2 * n> result;
	for (std::size_t i = 0; i < n; i++)
		result[i] = arr1[i];
	for (std::size_t i = n; i < 2 * n; i++)
		result[i] = arr2[i - n];
	return result;
}

template <class T, std::size_t n, class ... Arrays>
std::array<T, (n * (sizeof... (Arrays) + 1))> cat(std::array<T, n> arr, Arrays ... arrs) {
	std::array <T, (n * (sizeof... (arrs)))> arrcat = cat(arrs...);
	std::array<T, (n * ((sizeof... (arrs)) + 1))> result;
	for(std::size_t i = 0; i < n; i++)
		result[i] = arr[i];
	for (std::size_t i = n; i < (n * ((sizeof... (arrs)) + 1)); i++)
		result[i] = (arrcat[i - n]);
	return result;
}

template <class T, size_t n, size_t m>
struct Tie {
	std::vector<std::reference_wrapper<std::array<T, n>>> uncats;

	void operator =(const std::array<T, n * m>& rhs) {
		for (size_t i = 0; i < m; i++)
			for (size_t j = 0; j < n; j++)
				uncats[i].get()[j] = rhs[i * n + j];
	};

	void recur(std::array<T, n>& arr) {
		uncats.push_back(arr);
	};

	template <class ... Arrays>
	void recur(std::array<T, n>& arr, Arrays& ... arrs) {
		uncats.push_back(arr);
		recur(arrs ...);
	};

	Tie(std::array<T, n>& arr)
	{
		uncats.push_back(arr);
	};

	template<class ... Arrays>
	Tie(std::array<T, n>& arr, Arrays& ... arrs)
	{
		recur(arr, arrs ...);
	};
};

template <class T, std::size_t n, class ... Arrays>
Tie<T, n, (sizeof... (Arrays) + 1)>  uncat(std::array<T, n>& arr, Arrays& ... arrs) {
	return Tie<T, n, (sizeof... (arrs) + 1)>(arr, arrs ...);
}

int main() {
	message(std::cout, "% % %\n", 1, 2);
	return 0;
}