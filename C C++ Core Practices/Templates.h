#pragma once
#include<iostream>
#include<string>
#include<typeinfo>


namespace _Template {
	
	template<class type>
	void display(type _type) {
		const type_info& type_info = typeid(_type);
		
		if (typeid(_type) != typeid(int)) DebugBreak();
		std::cout << _type << std::endl;
	}

	template<class fn, class... args>
	void callFun(fn&& _fn, args&&... _args) {
		std::cout << "fn address: " << _fn << std::endl;
		_fn(1, 1);
	}

	void sum(int a, int b) {
		std::cout << a + b << std::endl;
	}

	void init() {

		int i = 10;
		std::cout << "fn address: "<< sum << std::endl;
		callFun(sum, 1);

		/*int i = 10;
		std::string str = "abc";
		display<int>(i);*/
	}
}

