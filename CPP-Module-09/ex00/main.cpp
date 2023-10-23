/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:28:47 by yaktas            #+#    #+#             */
/*   Updated: 2023/10/23 16:41:35 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
    Subject açıklama:

    Bu görevde, bir Bitcoin'in belirli bir tarihte ne kadar değer olduğunu hesaplayan bir program oluşturmanız isteniyor. 
    Programınız, bu işlemi yapmak için bir CSV formatında bir veritabanı kullanmalı. 
    Ayrıca, hesaplamanızı yapmanız gereken tarih ve değer çiftlerini içeren başka bir dosyayı da girdi olarak almalı.

    İşte görevinizi yerine getirirken takip etmeniz gereken kurallar:
    
    • Programınızın adı "btc" olmalı.
    • Programınız bir dosyayı argüman olarak almalıdır. Bu dosya, "tarih | değer" formatında her bir satır içermelidir.
    • Geçerli bir tarih her zaman "Yıl-Ay-Gün" formatında olmalıdır.
    • Geçerli bir değer, 0 ile 1000 arasında olan bir ondalık sayı veya pozitif bir tam sayı olmalıdır.
    
    Programınızın işleyişini özetlemek gerekirse:
    
    İkinci veritabanı dosyasındaki her bir tarih-değer çiftini kullanarak, bu tarihte Bitcoin'in değerini hesaplamalısınız.
    Eğer veritabanınızdaki bu tarihi doğrudan bulamazsanız, veritabanınızdaki en yakın tarihi kullanmalısınız, ancak daha düşük olan tarihi seçmelisiniz.
    Sonuçları standart çıktıya yazdırmalısınız.
    Ayrıca, bu görevi gerçekleştirmek için en az bir konteyner kullanmanız gerekiyor ve herhangi bir hata durumunu uygun hata mesajlarıyla ele almanız gerekiyor.
    
    Yani programınız, ikinci veritabanı dosyasındaki her bir tarih-değer çiftini alacak, veritabanındaki en yakın tarihi bulacak 
    ve bu tarihe karşılık gelen Bitcoin değerini hesaplayarak sonucu standart çıktıya yazdıracaktır. Eğer tarih veritabanınızda yoksa, 
    en yakın tarihi kullanmanız gerekmektedir. Bu işlemi bir konteyner içinde gerçekleştirmeniz gerekiyor.
*/


int main(int ac, char **av)
{
    if(ac == 2) {
        try
        {
            BitcoinExchange btc;
            btc.readData();
            std::ifstream infile(av[1]);
            if(!infile.is_open()){
                std::cout << "Error: Cant find file" << std::endl;
            }
            std::string line;
            std::getline(infile, line);
            while(std::getline(infile, line)) 
            {
                std::istringstream iss(line);
                std::string key_s, value_s;
                value_s.clear();
                if(std::getline(iss, key_s, '|') && iss >> value_s)
                {
                    key_s.erase(0, key_s.find_first_not_of(" \t\n\r\f\v"));
                    key_s.erase(key_s.find_last_not_of(" \t\n\r\f\v") + 1);
                    value_s.erase(0, value_s.find_first_not_of(" \t\n\r\f\v"));
                    value_s.erase(value_s.find_last_not_of(" \t\n\r\f\v") + 1);
                    if(!key_s[0]){
                        std::cerr << "Error: Date is not found" << std::endl;
                        continue;
                    }
                    if(btc.DateCheck(key_s) == false) {
                        std::cerr << "Error: Wrong Date => " << key_s << std::endl;
                        continue;
                    }
                    if(btc.AlphCheck(value_s) == false) {
                        std::cerr << "Error: Wrong Value => " << value_s << std::endl;
                        continue;
                    }
                    if(btc.AlphCheck(key_s) == false) {
                        std::cerr << "Error: Wrong Date has a alph => " << key_s << std::endl;
                        continue;
                    }
                    double value;
                    try 
                    {
                        std::stringstream vs(value_s);
                        vs >> value;
                    } 
                    catch (std::exception &e) {
                        std::cerr << "Error: invalid value in line: " << line << std::endl;
                        continue;
                    }
                    if (value < 0) {
                        std::cerr << "Error: not a positive number." << std::endl;
                        continue;
                    }
                    if (value > 1000) {
                        std::cerr << "Error: too large a number." << std::endl;
                        continue;
                    }
                    btc._exchange[key_s] = value;
                } else {
                    std::cerr << "Error: bad input => " << line << std::endl;
                    continue;
                }
                std::cout << key_s << " ==> " << btc._exchange[key_s] << " = " << btc.give_back_data(key_s, btc._exchange[key_s]) << std::endl;
            }
        } catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    } else {
        std::cout << "Error: Bad arguement." << std::endl;
    }
}