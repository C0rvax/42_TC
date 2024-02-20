
		printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}
		printf ${BLUE}"\n\t\t  Order nums\t\t\n"${DEF_COLOR}
		printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}

		ARG=""
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}1. [OK]${DEF_COLOR}"
		else
			printf "${RED}1. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2 3 4 5 6 7 8 9"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}2. [OK]${DEF_COLOR}"
		else
			printf "${RED}2. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2 3"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}3. [OK]${DEF_COLOR}"
		else
			printf "${RED}3. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}4. [OK]${DEF_COLOR}"
		else
			printf "${RED}4. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="0 1 2 3 4"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}5. [OK]${DEF_COLOR}"
		else
			printf "${RED}5. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}6. [OK]${DEF_COLOR}"
		else
			printf "${RED}6. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}7. [OK]${DEF_COLOR}"
		else
			printf "${RED}7. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="6 7 8"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}8. [OK]${DEF_COLOR}"
		else
			printf "${RED}8. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="2147483645 2147483646 2147483647"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}9. [OK]${DEF_COLOR}"
		else
			printf "${RED}9. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="-2147483648 -2147483647 -2147483646"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}10. [OK]${DEF_COLOR}"
		else
			printf "${RED}10. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}11. [OK]${DEF_COLOR}"
		else
			printf "${RED}11. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		ARG="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77"
		N=$(./push_swap $ARG | wc -l)
		if [ $N -eq 0 ]; then
			printf "${GREEN}12. [OK]${DEF_COLOR}"
		else
			printf "${RED}12. [KO]${DEF_COLOR}"
		fi
		R=$(valgrind --log-fd=1 ./push_swap $ARG | grep -Ec 'no leaks are possible|ERROR SUMMARY: 0')
		if [[ $R == 2 ]]; then
			printf "${GREEN}[MOK] ${DEF_COLOR}\n"
		else
			printf "${RED} [KO LEAKS] ${DEF_COLOR}\n"
		fi

		printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}
		printf ${BLUE}"\n\t\t  Random test with big nums\t\t\n"${DEF_COLOR}
		printf ${BLUE}"\n-------------------------------------------------------------\n\n"${DEF_COLOR}

		ARG=$(ruby -e "puts (-2147483648..-2147483149).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (-2147483648..-2147483149).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..498).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..498).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..497).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..497).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (-1..498).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (5000..5499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (50000..50499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (500000..500499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (5000000..5000499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (50000000..50000499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (500000000..500000499).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (0..450).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (250..720).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (10000..10460).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (100..250).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (90000..90460).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (-500..-9).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi

		ARG=$(ruby -e "puts (-50000..-49510).to_a.shuffle.join(' ')")
		N=$(./push_swap $ARG | wc -l)
		if [ $N -lt 5500 ]; then
			printf "${GREEN}[OK][5/5]${DEF_COLOR}"
		elif [ $N -gt 5500 ] && [ $N -lt 7000 ]; then
			printf "${YELLOW}[OK][4/5]${DEF_COLOR}"
		elif [ $N -gt 7000 ] && [ $N -lt 8500 ]; then
			printf "${RED}[KO][3/5]${DEF_COLOR}"
		elif [ $N -gt 8500 ] && [ $N -lt 10000 ]; then
			printf "${RED}[KO][2/5]${DEF_COLOR}"
		elif [ $N -gt 11500 ]; then
			printf "${RED}[KO][1/5]${DEF_COLOR}"
		fi
		S=$(./push_swap $ARG | ./checker_linux $ARG)
		if [ $S == "OK" ]; then
			printf "${GREEN} [OK]${DEF_COLOR}\n"
		else
			printf "${RED} [KO]${DEF_COLOR}\n"
		fi
		rm -rf 0
		make fclean >/dev/null
	fi
	make fclean >/dev/null
else
	echo -e "${rouge} ---------- WRONG OPTION! ----------"
fi
