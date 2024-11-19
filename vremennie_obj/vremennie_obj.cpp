#include <string>
#include <iostream>

//семантика перемещение рвэлью и лвэлью ссылки. Левосторонние это те, которые стоят слева от оператора присваивания, их можно взять по ссылке.
//правосторонне это те, которые стоят справа от оператора присваивания, на rvalue тоже можно получить ссылку, но с двумя аперсентами и с помощью семантики перемещения std::move
//ЕСЛИ МЫ ХОТИМ СДЕЛАТЬ ЛВАЛЮЕ -> РВАЛЮЕ ТО НУЖНО МУВ, А ЕСЛИ НАОБОРОТ ТО ДЕЛАТЬ КОНСТАНТНУЮ ССЫЛКУ

void copyFoo(std::string text) {}
void copyRefFoo(const std::string& text) {}
void MoveFoo(std::string&& text) {}

int main()
{
    std::string text = "some text";

    copyFoo(text);
    copyRefFoo(text);
    copyRefFoo("some another text");

    MoveFoo(std::move(text));

    return 0;
}