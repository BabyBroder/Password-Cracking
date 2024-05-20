cat README.md
sleep 2
cd src/GenerateDictionary
g++ -w -o make_dictionary make_dictionary.cpp
./make_dictionary
cd ..
python3 run.py
echo "I will remove the dictionary from the information in the owner file rar."
cd ../dictionary/information_user
rm -r *