cat README.md
sleep 2
cd src/GenerateDictionary
g++ -w -o make_dictionary make_dictionary.cpp
./make_dictionary
cd ../
echo "You need to give path to file"
echo "Example: /home/broder/test.rar"
echo "The rar file: "
read rar_file
echo "The target file: "
read -r target_file
if [ -s "$target_file" ] ; then
    python3 attack.py ${rar_file} "${target_file}"
else
    python3 attack.py ${rar_file}
fi
echo "I will remove the dictionary from the information in the owner file rar."
cd ../dictionary/information_user
rm -r *
