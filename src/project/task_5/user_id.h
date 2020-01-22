#pragma once
#include <string>

class user_id
{
    private:
    	std::string name_;
    	std::string id_;
    public:
    	user_id() : name_(), id_() {};
    	user_id(std::string name, std::string id) : name_(name), id_(id) {};

    	user_id(const user_id& user) : name_(user.name_), id_(user.id_) {};
    	user_id(user_id&& user) noexcept : name_(std::move(user.name_)), id_(std::move(user.id_)) {};

    	user_id& operator=(const user_id& user)
    	{
    		if (this == &user)
    			return *this;
    		name_ = user.name_;
    		id_ = user.id_;
    
    		return *this;
    	};

    	user_id& operator=(user_id&& user) noexcept
    	{
    		if (this == &user)
    			return *this;
    		name_ = std::move(user.name_);
    		id_ = std::move(user.id_);

    		return *this;
    	};

    	std::string name() const { return name_; };
    	std::string id() const { return id_; };
};

bool operator<(const user_id& userleft, const user_id& userright){
	return userleft.name() + userleft.id() < userright.name() + userright.id();
};

bool operator==(const user_id& userleft, const user_id& userright){
	return userleft.name() + userleft.id() == userright.name() + userright.id();
};

bool operator>(const user_id& userleft, const user_id& userright){
	return userleft.name() + userleft.id() > userright.name() + userright.id();
};