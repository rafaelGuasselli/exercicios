import requests

# Fetch submissions
response = requests.get("https://codeforces.com/api/user.status?handle=rafaelguasselli")
data = response.json()

if data['status'] == 'OK':
    submissions = data['result']

    # Open file for writing
    with open("all_submissions.txt", "w", encoding="utf-8") as f:
        for sub in submissions:
            problem = sub['problem']
            contest_id = problem.get('contestId', 'N/A')
            index = problem.get('index', 'N/A')
            name = problem.get('name', 'N/A')
            rating = problem.get('rating', 'N/A')
            tags = ", ".join(problem.get('tags', []))
            verdict = sub.get('verdict', 'N/A')
            
            f.write(f"{contest_id}-{index} | {name} | Verdict: {verdict} | Rating: {rating} | Tags: {tags}\n")

    print(f"Saved {len(submissions)} submissions to all_submissions.txt")
else:
    print("Error:", data.get('comment', 'Unknown error'))
