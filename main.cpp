#include <print>
#include "fmt/format.h"
#include "fmt/ranges.h"
import std.core;

struct Person
{
	std::string name;
	int age;
};

enum class CustomFormat { COMPACT, HUMAN };

template <>
struct std::formatter<Person>
{
	CustomFormat m_format = CustomFormat::COMPACT;

	constexpr auto parse(std::format_parse_context& ctx)
	{
		auto it = begin(ctx);
		if (it != end(ctx))
		{
			switch (*it)
			{
			case '#':
				m_format = CustomFormat::HUMAN;
				break;
			default:
				return it;
			}
			++it;
		}
		return it;
	}

	auto format(const Person& p, std::format_context& ctx) const
	{
		auto&& out = ctx.out();
		switch (m_format)
		{
		case CustomFormat::COMPACT:
			out = std::format_to(out, "Person: {} ({})", p.name, p.age);
			break;
		case CustomFormat::HUMAN:
			out = std::format_to(out, "Person{{\n  name: {}\n  age: {}\n}}", p.name, p.age);
			break;
		default: ;
		}
		return out;
	}
};
template <>
struct fmt::formatter<Person>
{
	CustomFormat m_format = CustomFormat::COMPACT;

	constexpr auto parse(fmt::format_parse_context& ctx)
	{
		auto it = std::begin(ctx);
		if (it != std::end(ctx))
		{
			switch (*it)
			{
			case '#':
				m_format = CustomFormat::HUMAN;
				break;
			default:
				return it;
			}
			++it;
		}
		return it;
	}
	template <typename FormatContext>
	auto format(const Person& p, FormatContext& ctx) const
	{
		// return format_to(ctx.out(), "Person: {} ({})", p.name, p.age);
		auto&& out = ctx.out();
		switch (m_format)
		{
		case CustomFormat::COMPACT:
			out = fmt::format_to(out, "Person: {} ({})", p.name, p.age);
			break;
		case CustomFormat::HUMAN:
			out = fmt::format_to(out, "Person{{\n  name: {}\n  age: {}\n}}", p.name, p.age);
			break;
		default: ;
		}
		return out;
	}
};

int main()
{
	std::vector v{1, 2, 3, 4, 5};
	for (auto i : v)
	{
		std::println("{}", i);
	}
	fmt::println("{}", v);
	Person p{"liyixin", 30};
	std::println("{}", p);
	std::println("{:#}", p);
	fmt::println("{}", p);
	fmt::println("{:#}", p);
	std::map<std::string, int> m{{"a", 1}, {"b", 2}, {"c", 3}};
	fmt::println("{}", m);
	return 0;
}