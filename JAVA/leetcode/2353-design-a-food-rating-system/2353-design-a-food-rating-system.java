class FoodComparator implements Comparator<Food> {
    public int compare(Food a, Food b) {
        if(a.rating - b.rating != 0) return b.rating - a.rating;
        else return a.food.compareTo(b.food);
    }
}

class Food {
    public String food;
    public int rating;
    public String cuisine;
    
    public Food(String name, String cui, int score) {
        this.food = name;
        this.rating = score;
        this.cuisine = cui;
    }
}

class FoodRatings {
    
    private HashMap<String, Food> food2cuisine;
    private HashMap<String, PriorityQueue<Food>> cuisine2food; 

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        this.food2cuisine = new HashMap<String, Food>();
        this.cuisine2food = new HashMap<String, PriorityQueue<Food>>(); 
        for(int i=0;i<foods.length;i++) {
            Food cur = new Food(foods[i], cuisines[i], ratings[i]);
            this.food2cuisine.put(foods[i], cur);
            if (cuisine2food.containsKey(cuisines[i])) {
                PriorityQueue<Food> pq = cuisine2food.get(cuisines[i]);
                pq.add(cur);
            }
            else {
                PriorityQueue<Food> pq = new PriorityQueue<Food>(foods.length, new FoodComparator());
                pq.add(cur);
                cuisine2food.put(cuisines[i], pq);
            }
            
        } 
    }
    
    public void changeRating(String food, int newRating) {
        Food curr = food2cuisine.get(food);
        PriorityQueue<Food> pq = cuisine2food.get(curr.cuisine);
        pq.remove(curr);
        curr.rating = newRating;
        pq.add(curr);
        return;
    }
    
    public String highestRated(String cuisine) {
        return cuisine2food.get(cuisine).peek().food;
    }
}

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings obj = new FoodRatings(foods, cuisines, ratings);
 * obj.changeRating(food,newRating);
 * String param_2 = obj.highestRated(cuisine);
 */