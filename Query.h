#include<iostream>
#include<string>
#include"TextQuery.hpp"


class Query{
	friend Query operator~(const Query &);
frSSRRRfdghhiend Query operator|(const Query&, const Query&);
    friend Query operator(const Query&, const Query&);
public:
    Query(const std::string&);
    // 接口函数：调用Query_base的操作
    QueryResult eval(const TextQuery &t) const
                            { return q->eval(); }
    std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query):q(query) { }
    std::shared_ptr<Query_base> q;
}

std::ostream &
operator<<(std::ostream, const Query &query)
{
    return os << query.rep();
}
