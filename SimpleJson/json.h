#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <variant>

namespace json {

	class Node;
	using Dict = std::map<std::string, Node>;
	using Array = std::vector<Node>;
	using node = std::variant<std::nullptr_t, Array, Dict, bool, int, double, std::string>;

	// Эта ошибка должна выбрасываться при ошибках парсинга JSON
	class ParsingError : public std::runtime_error {
	public:
		using runtime_error::runtime_error;
	};

	class Node : public node {
	public:
		Node() = default;
		Node(std::nullptr_t) { node_ = {}; }
		Node(Array array) :node_(std::move(array)) {}
		Node(Dict dictonary) :node_(std::move(dictonary)) {}
		Node(bool value) :node_(std::move(value)) {}
		Node(int value) :node_(std::move(value)) {}
		Node(double value) :node_(std::move(value)) {}
		Node(std::string str) :node_(std::move(str)) {}

		bool IsNull() const;
		bool IsInt() const;
		bool IsDouble() const;
		bool IsPureDouble() const;
		bool IsString() const;
		bool IsBool() const;
		bool IsArray() const;
		bool IsMap() const;

		const Array& AsArray() const;
		bool AsBool() const;
		double AsDouble() const;
		int	AsInt() const;
		const Dict& AsMap() const;
		const std::string& AsString() const;
		const node& GetNode() const { return node_; }

		/*
		bool operator==(Node& right) {
			if (this->IsNull() && right.IsNull()) {
				return true;
			}
			if (this->IsInt() && right.IsInt()) {
				return this->AsInt() == right.AsInt();
			}
			if (this->IsPureDouble() && right.IsPureDouble()) {
				return this->AsDouble() == right.AsDouble();
			}
			if (this->IsString() && right.IsString()) {
				return this->AsString() == right.AsString();
			}
			if (this->IsBool() && right.IsBool()) {
				return this->AsBool() == right.AsBool();
			}
			if (this->IsArray() && right.IsArray()) {
				return this->AsArray() == right.AsArray();
			}
			if (this->IsMap() && right.IsMap()) {
				return this->AsMap() == right.AsMap();
			}
			return false;
		} */

	private:
		node node_;
	};

	class Document : public Node {
	public:
		explicit Document(Node root);

		const Node& GetRoot() const;

	private:
		Node root_;
	};

	Document Load(std::istream& input);

	void Print(const Document& doc, std::ostream& output);

	inline bool operator==(json::Node left, json::Array right) {
		if (std::holds_alternative<Array>(left)) {
			if (std::get<Array>(left) == right) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
}  // namespace json