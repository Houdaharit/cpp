#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain&);
		Brain& operator = (const Brain&);
		~Brain();
		void setIdea(int, const std::string &); 
		std::string getIdea(int) const;
};
#endif
