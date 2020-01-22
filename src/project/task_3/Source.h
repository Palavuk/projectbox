#include <cstring>
#include <iostream>
#include <cstring>
#include <array>
#include <functional>
#include <vector>

/**
 * функция message, которая работает аналогично функции printf.
 * Первый аргумент функции — поток, куда будут выводится символы. 
 * Второй аргумент функции — шаблон строки, которая отобразится на экране, в котором символом % обозначены места вставки объектов. 
 * Остальные аргументы функции — это объекты, которые нужно вставить на место %. Функция при вызове выводит сообщение на стандартный вывод. Например,
 * message(std::cout, "% + % = %\n", 'a', 2, 3.0) выведет на экран a + 2 = 3.
 */
template<class strm>
void message(strm& stream, const char* format)
{
	stream << format;
}

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

/**
 * функция cat, которая соединяет произвольное количество массивов
в один большой массив. Функция должна принимать произвольное количество
аргументов и возвращать объект типа std::array (это один из новых классов
стандартной библиотеки C++, который представляет собой статический массив заданного размера). Пример вызова функции:
2
std::array<float,3> vec1{1.0f,2.0f,3.0f};
std::array<float,3> vec2{4.0f,5.0f,6.0f};
std::array<float,6> r = cat(vec1, vec2); // 1 2 3 4 5 6

 */
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

/**
 * функция Tie, которая работает также как std::tie, но для массивов, имеющих тип std::array<T,N>
 */

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


