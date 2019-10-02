#!/bin/bash

function save_mail {
	mkdir pages 2> /dev/null	
	file="$RANDOM$RANDOM"
	while [ -f "pages/$file" ]; do	
		file="$RANDOM$RANDOM"
	done;
	cat $1 > "pages/$file"
	echo "pages/$file"
}

function process_email_del {
	dat=`cat $1 | grep 'SUBJECT: DEL' | sed 's/SUBJECT: DEL \(.*\) [0-9]*^/\1/' `
	nom=`cat $1 | grep 'SUBJECT: DEL' | sed 's/SUBJECT: DEL .* \([0-9]*\)$/\1/' `
	echo $nom
	dat=aaaa
	index_first=`cat index.html | grep -n "<li><a .*</a> ($dat)</li>" | head -n 1 | cut -d: -f1`	
	index_last=`cat index.html  | grep -n "<li><a .*</a> ($dat)</li>" | tail -n 1 | cut -d: -f1`	
	echo $index_first
	echo $index_last
}

function process_email_new {
	loc=`save_mail $1`
	index=`cat index.html | grep -n "<li>" | tail -n 1 | cut -d: -f1`	
	cat index.html | head -n $index > index.new.html
	dat=`date +"(%d. %m. %Y)"`
	title=`	cat $1 | grep "SUBJECT: *" | sed -e 's/SUBJECT: //'`
	echo $title
	echo "		<li><a href='$loc'>$title</a>$dat</li>" >> index.new.html
	index_s=$((index + 1))
	cat index.html | tail -n +$index_s >> index.new.html
	mv index.new.html index.html
}

function main {
	from_mail=`cat $1 | grep 'FROM: ' | sed -e 's/^FROM: //'`

	FROM='vilem.zouhar@gmail.com ahoj@seznam.cz doktor@malay.ml'
	echo $FROM | tr ' ' '\n' | while read line; do
		if [ $from_mail = $line ]; then
			if cat $1 | grep "SUBJECT: DEL*" > /dev/null; then
				process_email_del $1
			else
				process_email_new $1
			fi
		fi
	done
}

until mkdir .lock~ 2> /dev/null; do
	echo "Error: active directory currently in use. Sleeping for 2s."
	sleep 2
done
main $1
rm -R .lock~
