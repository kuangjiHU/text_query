#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <memory>

class QueryResult;

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream& ifs);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};


class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, 
                std::shared_ptr<std::set<size_t>> p,
                std::shared_ptr<std::vector<std::string>> f):
                sought(s), lines(p), file(f){ }
private:
	std::string sought; // 要查询的单词
	std::shared_ptr<std::vector<std::string>> file; // 输入文件
	std::shared_ptr<std::set<size_t>> lines; // 保存出现的行号
};

