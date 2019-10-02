#/bin/bash
awk -e '
	BEGIN {
		i = 1;
	}

	{
		for(k = 1; k <= NF; k++)
		{
	#		print k, $k;
			a[i,k] = $k;
		}
		i++;	
		t=NF;
	}

	END {
		for(k = 1; k <= t; k++) {
			m = 0;
			for(l = 1; l <= t; l++) {
				printf("%02d ", a[k,l]);
				if(m < a[k,l])
					m = a[k,l]	
			}
			print "# ",m;
		}
	}

' < $1 > $2
