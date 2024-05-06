# DSA-final-project-decision-tree-2270
Hi, welcome to my term project repo for CSPB 2270 data structure and algorithm course!

## Data structure implemented
In this project, I studied a structure called **Decision Tree**. Specifically, I used a tree-based structure to implement decision making process. This structure can also be used for making predictions.

Why decision tree? In my everyday job, I work in risk decisioning area as a technical product manager for a global e-commerce platform. Every second, there are thousands decisions executed to prevent fraud and attack from happending. Decisioning are made across various user touchpoint in order to protect both our customers and the company from loss. A typical example is transaction risk where we want to evaluate chargeback risk and decision whether we should block or allow the current transaction. 
Understanding the underlying mechanism of how decisioning works is highly important for me. Therefore, I decided to pick decision tree structure for my project.

## Explanation of the data structure
A decision tree can be a binary tree or generic(N-ary) tree. It always has one single root node, and can have a few child nodes. An edge connects a parent node to its child nodes. At each node, a test is executed which generates a decision that indicates which one of the child node should come next if it's not a leaf. A leaf node is a terminal node where no further tests or decisions are to be made after it and it gives a final outcome of the decision tree. Just like rolling a dice can give 6 possible values, a decision tree can have multiple possible outcomes. 

In my project, I implemented binary decision tree because it's the most basic since any N-ary tree can be converted to a binary decision tree.
![image](https://github.com/emilypiano88/DSA-final-project-decision-tree-2270/assets/157334954/9e807557-b9a5-47f3-954f-e9db821f2e2c)

What's quite different from a binary search tree is that a decision tree is very application specific. Each node of a decision tree is very unique in logic while BST nodes are more similar making BST a generic tree. Therefore, I must have have a use case to implement and walkthrough a decision tree.

## Use case introduction
I chose "Graduate Admission Decision" as my use case to implement decision tree structure.

**Problem Statement:** A post-bacc student applying to CS master at Boulder wants to know if she will be admitted by the graduate school.
In real-world, admission office has admission process into 3 high-level steps:
1. Set admissions criteria (unknown to students)
2. Evaluate all students profile
3. Make an admission recomendation

Consequently, by assuming cirtain admissions criteria, a student can make a prediction of their own admission outcome: admitted, waitlisted, or rejected. However, in real world, we don't know the exact admission criteria. We can only make assumption by looking at previous students' admission results.

In part 1 of my project, I use **heuristic/empirical** method to derive a hypothetical admission decisioning process, which is illustrated below. My walkthrough video is also based on this decision tree.
![image](https://github.com/emilypiano88/DSA-final-project-decision-tree-2270/assets/157334954/13338998-33be-4bdf-83dc-6f40831f812e)

In part 2 of my project, I explored how machine learning algothm can be used for deriving a decision tree. This is a more **methodological/scientific** method.

## How to run my project
### Part 1
This is very similar to our usual homework assignment, except that I designed everything from scratch including functions(traverse/initialize) and structs(node/profile). A takeaway is that "Design" is the most important procedure before doing any coding. I struggled a bit at first to design the right overal structure until I finally can put things in the most appropriate file for the whole program to be executable. 

To run my code, simple run cmake..  and make &&./run_app in terminal, and you'll get the admission prediction of a hypothetical student named "Alice". If you want to make admission prediction of a different student, just update two lines in main.cpp: creating a new student profile and giving parameter in order of: gpa, test_score, match_score, funding, motiv, recom.

    student_profile Alice = init_profile(3.2, 700, 8, 0, 1, 0);     
    
    int x = predict_outcome(my_root, Alice);

***Walkthrough video:***

Google Drive Folder:
https://drive.google.com/drive/folders/1_ui7JMktaVGipA9GgJf7BZzdS1wwa3jA?usp=drive_link

### Part 2
An obvious drawback in part 1 is that the decision tree was constructed by hand. In part 2, I'm examine decision tree as an machine learning algothm. First, I prepared some training set with manual labels:
![image](https://github.com/emilypiano88/DSA-final-project-decision-tree-2270/assets/157334954/976f7b81-35f0-4310-a5c5-c62521ed4762)


***Walkthrough notebook:***

https://github.com/emilypiano88/DSA-final-project-decision-tree-2270/blob/c4ca850f364aea37f0f23b57a5d2560544419570/DecisionTreeML.ipynb


## Final Reflection
What could I have done better:
1. Seek help earlier
2. Design before coding
    
