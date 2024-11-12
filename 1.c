# ls command examples
ls -l
ls -a
ls -lh
ls -R

# echo command examples
echo -e "Hello\nWorld"
echo -n "Hello, "

# read command examples
read -p "Enter your name: " name
read -t 5 name
read -s password

# cat command examples
cat -n filename.txt
cat -s filename.txt
cat -b filename.txt

# touch command examples
touch -c filename.txt
touch -t 202401011230 filename.txt
touch -a filename.txt

# test command examples
test -f filename.txt && echo "File exists."
test -d /path/to/directory && echo "Directory exists."
test -e filename.txt && echo "File or directory exists."

# arithmetic and conditional loops examples
if [ "$a" -eq "$b" ]; then
  echo "a equals b"
fi

for i in 1 2 3; do
  echo "Number: $i"
done

count=0
while [ $count -lt 5 ]; do
  echo "Count: $count"
  count=$((count + 1))
done

# grep command examples
grep -i "pattern" filename.txt
grep -v "pattern" filename.txt
grep -r "pattern" /path/to/directory
grep -c "pattern" filename.txt

# sed command examples
sed -e 's/old/new/g' filename.txt
sed -i 's/old/new/g' filename.txt
sed -n '2p' filename.txt

# find command examples
find /path/to/search -name "filename.txt"
find /path/to/search -type f -name "*.txt"
find /path/to/search -size +100M
find /path/to/search -name "*.log" -exec rm {} \;
find /path/to/search -mtime -7

# rmdir command examples
rmdir dirname
rmdir -p /path/to/empty/parent/dir

# rm command examples
rm -r dirname
rm -f filename.txt
rm -i filename.txt
rm -d emptydir

# mv command examples
mv filename.txt /new/path/
mv oldname.txt newname.txt
mv -i file1.txt /path/to/destination/
mv -f file1.txt /path/to/destination/

# mkdir command examples
mkdir -p /path/to/nested/directory
mkdir -v dirname
mkdir -m 755 dirname
