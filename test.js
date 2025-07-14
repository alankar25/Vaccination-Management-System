
fetch('https://api.github.com/users/hiteshchoudhary')
  .then((response) => {
    // Return the Promise from response.json() so the next .then() can catch its resolved value
    return response.json();
  })
  .then((data) => {
    // 'data' here is the actual parsed JSON object
    console.log(data);
  })
  .catch((error) => console.log(error));

  console.log("Hello World");
