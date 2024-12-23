void	Harl::complain(std::string level)
{
	static const struct
	{
		std::string	keyword;
		void		(Harl::*func)(void);
	}
	selection[] =
	{
		{ "DEBUG", &Harl::debug },
		{ "INFO", &Harl::info },
		{ "WARNING", &Harl::warning },
		{ "ERROR", &Harl::error },
	};
	for (size_t i = 0; i < sizeof(selection) / sizeof(selection[0]); i++)
	{
		if (level == selection[i].keyword)
			(this->selection[i].func)();
	}
