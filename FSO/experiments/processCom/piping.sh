while [ true ]
do
	sleep 1; 
	echo "ola" > coll*& cat coll* >> f 
done

