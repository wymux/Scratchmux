const proto = {
    sender: 'luis@tjoj.com',
}

const transaction = {
    sender: 'luis@tjoj.com',
    recipient: 'luke@tjoj.com',
}

const hashTransaction = Object.create(transaction);

hashTransaction.calculateHash = function calculateHash() {
    const data = [this.sender, this.recipient].join('');
    let hash = 0, i = 0;
    while (i < data.length)
	hash = ((hash << 5) - hash + data.charCodeAt(i++)) << 0;
    return hash**2;
}

const moneyTransaction = Object.setPrototypeOf({}, hashTransaction);
moneyTransaction.funds = 0.0;

moneyTransaction.addFunds = function addFunds(funds = 0) {
    this.funds += Number(funds);
};
moneyTransaction.addFunds(10.0);

console.log(moneyTransaction.calculateHash(),
	    moneyTransaction.funds,
	    moneyTransaction.sender,
	    moneyTransaction.recipient);

function Transaction(sender, recipient) {
    this.sender = sender;
    this.recipient = recipient;
}

function HashTransaction(sender, recipient) {
    if (!new.target)
	return new HashTransaction(sender, recipient);

    Transaction.call(this, sender, recipient);

    HashTransaction.prototype.calculateHash = function calculateHash() {
	const data = [this.sender, this.recipient].join('');
	let hash = 0, i = 0;
	while (i < data.length)
	    hash = ((hash << 5) - hash + data.charCodeAt(i++)) << 0;
	return hash**2;
    }
}

const tx = new HashTransaction("luis@tjoj.com", "luke@tjoj.com");
const tx1 = new HashTransaction("luis@tjoj.com", "luke@tjoj.com");
const tx2 = new HashTransaction("luis@tjoj.com", "luke@tjoj.com");

tx.calculateHash();
tx.sender;

console.log(tx1.calculateHash === tx2.calculateHash);

Transaction.pr
