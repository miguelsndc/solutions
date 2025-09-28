g++ -Wall -Wconversion -Wfatal-errors -g -std=c++20 -fsanitize=undefined,address "$1" -o /tmp/temp_exec && \
/tmp/temp_exec < "./in" > "./out" && \
cat "./out"

# chmod +x ~/path/c.sh
# echo 'export PATH=$PATH:~/scripts' >> ~/.bashrc
# source ~/.bashrc
# daí so chamar c.sh <arquivo>