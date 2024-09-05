class Money:
    def __init__(
        self,
        amount: int,
        currency: Currency
    ):
        if amount < 0:
            raise ValueError('money should be larger than 0.')
        if currency is None:
            raise ValueError('specify the units of currency.')
        
        self.__amount = amount
        self.__currency = currency
    
    def add(self, other: Money):
        added = self.__amount + other.amount
        return Money(added, self.__currency)