#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string number;
        std::string secret;

    public:
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const std::string& getNickName() const;
        const std::string& getNumber() const;
        const std::string& getSecret() const;
        void setFirstName(const std::string& name);
        void setLastName(const std::string& name);
        void setNickName(const std::string& name);
        void setNumber(const std::string& name);
        void setSecret(const std::string& name); 
};

#endif // CONTACT_HPP
