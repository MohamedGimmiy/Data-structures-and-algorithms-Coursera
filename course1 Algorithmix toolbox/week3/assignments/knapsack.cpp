#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;


struct Item
{
	double weight;
	double value;
};

double knapsack(double KnapsackWeight, vector<Item>things) {

	//vector<double>amounts(things.size(), 0.0);
	double totalVal = 0.0000;

	double maxValuableElement = 0.0000;
	double selectedElement;
	int n = things.size();

	for (int i = 0; i<n; i++) {
		if (KnapsackWeight == 0.0) {
			return totalVal;
		}



		double weight = min(KnapsackWeight, things.at(i).weight);
		// increase the total value by the chosen elemnt to take
		totalVal += weight * (things.at(i).value / things.at(i).weight);

		// decrease that weight from the element
		things.at(i).weight -= weight;

		// add the amount taken to our bag of this element
		//amounts.at(i) += weight;

		// decrease the weight space of our bag until it reachs zero
		KnapsackWeight -= weight;

	}

	// cout amounts
	/*for (int i = 0; i<amounts.size(); i++) {
		cout << amounts.at(i) << " ";
	}*/
	return totalVal;

}

double ratio(Item item1, Item item2) {
	return item1.value / item1.weight > item2.value / item2.weight;
}

int main() {

	int itemsNumber;
	double KnapsackWeight, value, weight;
	vector<Item> items;
	cin >> itemsNumber >> KnapsackWeight;

	for (int i = 0; i<itemsNumber; i++) {
		cin >> value >> weight;
		Item item;
		item.weight = weight;
		item.value = value;
		items.push_back(item);
	}

	// optimization of algorithm
	// sorting our array on criteria has maximum (value/weight)
	sort(items.begin(), items.end(), ratio);

	//for (int i = 0; i < items.size(); i++) {
	//	cout << items.at(i).value;
	//}
	printf("%0.4f", knapsack(KnapsackWeight, items)) ;
	return 0;
}