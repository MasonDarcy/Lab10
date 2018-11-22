#!/bin/bash



n=$(./tempRead)
i=1
d=0

while [ $i == 1 ]

	do
		

		c=$(./tempRead)
		./tempRead
		
		if [ $? -ne 0 ]
		then
			echo Failed to get Temperature
			gpio write 0 0
			gpio write 1 0
			gpio write 2 0
			exit 1
		fi

		let "d=c-n"

		if [ $d -lt 1000 ]
			then
				gpio write 0 0
				gpio write 1 0
				gpio write 2 0
			fi


		if [ $d -gt 1000 ]
			then
				if [ $d -lt 2000 ]
				then
					gpio write 2 0
					gpio write 1 0 
					gpio write 0 1
				fi
			fi
		
		if [ $d -gt 2000 ]
			then
				if [ $d -lt 3000 ]
				then
					gpio write 0 0
					gpio write 2 0
					gpio write 1 1
				fi
			fi	

		if [ $d -gt 3000 ] 
			then
				gpio write 0 0
				gpio write 1 0
				gpio write 2 1
			fi

			echo "$d"
			
			sleep 5

	done


