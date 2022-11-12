#include <QCoreApplication>

#include <QStack>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(4);

    while(!myStack.isEmpty()){
        qDebug() << myStack.pop();
    }

    return a.exec();
}
