from tkinter import*
import random
import time;

root=Tk()
root.geometry("1600x800+0+0")
root.title("chizoba resturant")
text_input=StringVar()
operator=""
Tops =Frame(root, width = 1600,height =70, bg ="powder blue", relief=SUNKEN)
Tops.pack(side=TOP)

f1 =Frame(root, width = 800, height =700, relief=SUNKEN)
f1.pack(side=LEFT)

f2 =Frame(root, width = 300,height =700,  relief=SUNKEN)
f2.pack(side=RIGHT)
#===============time==============
localtime=time.asctime(time.localtime(time.time()))
#===============systeminfo===========
lblInfo=Label(Tops, font=("arial", 30, "bold"),text= " chizoba foodies", fg="black", bd=10, anchor ="w")
lblInfo.grid(row=0, column=0)
lblInfo=Label(Tops, font=("time roman", 10, "bold"),text= localtime, fg="black", bd=10, anchor ="w")
lblInfo.grid(row=1, column=0)
#===================calaculator=============
def btnclick(numbers):
    global operator
    operator=operator+str(numbers)
    text_input.set(operator)

def btnClearDisplay():
    global operator
    operator=""
    text_input.set("")

def btnEQUAL():
    global operator
    sumup= str(eval(operator))
    text_input.set(sumup)
    operator=""

def Ref():
    x=random.randint(12908, 500876)
    randomRef= str(x)
    rand.set(randomRef)
    
def qExit():
    root.destroy()
    
    
def Reset():
    rand.set("")
    Fries.set("")
    Rice.set("")
    Egg.set("")
    BEER.set("")
    bugger.set("")
    chicken.set("")
    Total.set("")
    Drinks.set("")
    service_charge.set("")
    tax.set("")
    sub_total.set("")
    Cost.set("")

    
txtDisplay=Entry(f2, font=('arial', 20, 'bold'), textvariable=text_input, bd=20, insertwidth=4, bg='powder blue', justify='right')
txtDisplay.grid(columnspan=4)
#------------------------------------------------------------------------------
btn7=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="7", bg='powder blue', command=lambda:btnclick(7)). grid(row=2, column=0)


btn8=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="8", bg='powder blue', command=lambda:btnclick(8)). grid(row=2, column=1)


btn9=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="9", bg='powder blue', command=lambda:btnclick(9)). grid(row=2, column=2)

Addition=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="+", bg='powder blue', command=lambda:btnclick("+")). grid(row=2, column=3)
#-------------------------------------------------------------------------------------------
btn1=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="1", bg='powder blue', command=lambda:btnclick(1)). grid(row=3, column=0)


btn2=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="2", bg='powder blue', command=lambda:btnclick(2)). grid(row=3, column=1)


btn3=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="3", bg='powder blue', command=lambda:btnclick(3)). grid(row=3, column=2)

Subtraction=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="-", bg='powder blue', command=lambda:btnclick("-")). grid(row=3, column=3)
#-------------------------------------------------------------------------------------
btn4=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="4", bg='powder blue', command=lambda:btnclick(4)). grid(row=4, column=0)


btn5=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="5", bg='powder blue', command=lambda:btnclick(5)). grid(row=4, column=1)


btn6=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="6", bg='powder blue', command=lambda:btnclick(6)). grid(row=4, column=2)

Multiplication=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="*", bg='powder blue', command=lambda:btnclick("*")). grid(row=4, column=3)
#-----------------------------------------------------------------------------------------
btn0=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="0", bg='powder blue', command=lambda:btnclick(0)). grid(row=5, column=0)


btnClear=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="C", bg='powder blue', command=btnClearDisplay). grid(row=5, column=1)


btnEquall=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="=", bg='powder blue', command=btnEQUAL). grid(row=5, column=2)

Division=Button(f2,padx=16,pady=16,bd=8, fg ='black', font=('arial' ,20, 'bold'),
            text="/", bg='powder blue', command=lambda:btnclick("/")). grid(row=5, column=3)

#===========================REASTURANT INFO1=============================
rand = StringVar()
Fries= StringVar()
Rice = StringVar()
Egg= StringVar()
BEER= StringVar()
Bugger= StringVar()
chicken= StringVar()
Total =StringVar()
Drinks= StringVar()
service_charge= StringVar()
tax= StringVar()
sub_total= StringVar()
Cost= StringVar()
lblReference = Label(f1, font=('ariel', 12, 'bold'), text='Refrence', bd=10, anchor= 'w')
lblReference .grid(row=0, column=0)
txtReference = Entry (f1, font=('ariel', 12, 'bold'), textvariable=rand, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtReference.grid(row=0, column=1)


lblFries = Label(f1, font=('ariel', 12, 'bold'), text='Large Fries', bd=10, anchor= 'w')
lblFries.grid(row=1, column=0)
txtFries = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Fries, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtFries.grid(row=1, column=1)

lblEgg = Label(f1, font=('ariel', 12, 'bold'), text='Egg ("boiled or fried")', bd=10, anchor= 'w')
lblEgg.grid(row=2, column=0)
txtEgg = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Egg, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtEgg.grid(row=2, column=1)

lblBugger = Label(f1, font=('ariel', 12, 'bold'), text='Chicken_Bugger', bd=10, anchor= 'w')
lblBugger.grid(row=3, column=0)
txtBugger = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Bugger, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtBugger.grid(row=3, column=1)

lblDrinks = Label(f1, font=('ariel', 12, 'bold'), text='Drinks', bd=10, anchor= 'w')
lblDrinks.grid(row=4, column=0)
txtDrinks = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Drinks, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtDrinks.grid(row=4, column=1)

lblRice = Label(f1, font=('ariel', 12, 'bold'), text='All_Type_Of_Rice', bd=10, anchor= 'w')
lblRice.grid(row=5, column=0)
txtRice = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Rice, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtRice.grid(row=5, column=1)

lblchicken = Label(f1, font=('ariel', 12, 'bold'), text='chicken', bd=10, anchor= 'w')
lblchicken.grid(row=5, column=0)
txtchicken = Entry (f1, font=('ariel', 12, 'bold'), textvariable=chicken, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtchicken.grid(row=6, column=1)

#----------------------------REASTUTANT INFO2------------------------
lblBEER = Label(f1, font=('ariel', 12, 'bold'), text='BEER', bd=10, anchor= 'w')
lblBEER .grid(row=0, column=2)
txtBEER = Entry (f1, font=('ariel', 12, 'bold'), textvariable=BEER, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtBEER.grid(row=0, column=3)


lblCost = Label(f1, font=('ariel', 12, 'bold'), text='Cost', bd=10, anchor= 'w')
lblCost.grid(row=1, column=2)
txtCost = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Cost, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtCost.grid(row=1, column=3)

lblservice_charge = Label(f1, font=('ariel', 12, 'bold'), text='Service_Charge', bd=10, anchor= 'w')
lblservice_charge.grid(row=2, column=2)
txtservice_charge = Entry (f1, font=('ariel', 12, 'bold'), textvariable=service_charge, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtservice_charge.grid(row=2, column=3)

lblsub_total = Label(f1, font=('ariel', 12, 'bold'), text='sub_total', bd=10, anchor= 'w')
lblsub_total.grid(row=3, column=2)
txtsub_total = Entry (f1, font=('ariel', 12, 'bold'), textvariable=sub_total, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtsub_total.grid(row=3, column=3)

lbltax = Label(f1, font=('ariel', 12, 'bold'), text='Tax', bd=10, anchor= 'w')
lbltax.grid(row=4, column=2)
txttax = Entry (f1, font=('ariel', 12, 'bold'), textvariable=tax, bd=10,insertwidth=4, bg="powder blue", justify="right")
txttax.grid(row=4, column=3)

lblTotal = Label(f1, font=('ariel', 12, 'bold'), text='TOTAL', bd=10, anchor= 'w')
lblTotal.grid(row=5, column=2)
txtTotal = Entry (f1, font=('ariel', 12, 'bold'), textvariable=Total, bd=10,insertwidth=4, bg="powder blue", justify="right")
txtTotal.grid(row=5, column=3)

#----------------------BUTTONS----------------------
btnTotal=Button(f1,padx=16, pady=8, bd=16, fg="black",font=('ariel', 12, 'bold'),width=10, text="Total",bg="powder blue", command= Ref).grid(row=7, column=1)

btnReset=Button(f1,padx=16, pady=8, bd=16, fg="black",font=('ariel', 12, 'bold'),width=10, text="Reset",bg="powder blue", command= Reset).grid(row=7, column=2)

btnExit=Button(f1,padx=16, pady=8, bd=16, fg="black",font=('ariel', 12, 'bold'),width=10, text="Quit",bg="powder blue", command=   qExit).grid(row=7, column=3)

root.mainloop()            
