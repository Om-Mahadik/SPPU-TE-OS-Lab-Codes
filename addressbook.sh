#!/bin/bash

create(){
        echo "Enter the name for the Addressbook"
        read ADDRESS_BOOK
        touch $ADDRESS_BOOK.txt
        echo "Addressbook with name $ADDRESS_BOOK.txt is created."
}

view(){
	echo "Enter the name of the person you want to search"
	read name
	grep "$name" $ADDRESS_BOOK || echo "No Match found"
}

insert(){
	echo "Enter the number of records you want to add: "
	read total_records

	for((i=1; i<=total_records; i++)); do
		echo "Record $i: "
		echo "Enter name: "
		read name
		echo "Enter phone number: "
		read phone
		echo "Enter address: "
		read address
		echo

		echo "Name: $name, Phone: $phone, Address: $address" >> $ADDRESS_BOOK
		echo "Record $i added Successfully!"
	done
}

delete(){
	echo "Enter the name of the person you want to delete record of: "
	read name

	if grep -q "$name" $ADDRESS_BOOK; then
	sed -i "/Name: $name/d" $ADDRESS_BOOK
	echo "Record deleted successfully!"
	else
	echo "Record not found."
	fi
}

modify() {
	echo "Enter the name of the person to modify the record of: "
	read name

	if grep -q "$name" $ADDRESS_BOOK; then
	sed -i "/Name: $name/d" $ADDRESS_BOOK
	echo "Enter new Name: "
	read name
	echo "Enter new Phone No.: "
	read phone
	echo "Enter new Address: "
	read address

	echo "Name: $name, Phone: $phone, Address: $address" >> $ADDRESS_BOOK
	echo "Record modified successfully!"
	else
	echo "Record not found"
	fi
}

exitbook(){
	echo "Exiting the program."
	exit
}

while true; do
	echo -e "\nAddress book Menu"
	echo "a) Create Address Book"
	echo "b) View Addressbook"
	echo "c) Insert a Record"
	echo "d) Delete a Record"
	echo "e) Modify a Record"
	echo "f) Exit"
	echo -e "\nEnter your Choice: "

	read choice

	case $choice in
		a) create;;
		b) view;;
		c) insert;;
		d) delete;;
		e) modify;;
		f) exitbook;;
		*) echo "Invalid Choice. Please try again.";;
	esac
done
