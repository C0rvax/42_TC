#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed &operator=(Fixed const & rhs);
		~Fixed();

	private:
		static int	m_fractBits;
		int			m_fix;
};
#endif // !FIXED_HPP
