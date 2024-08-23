#!/usr/bin/node

const axios = require('axios');

// Get the Movie ID
const movieId = process.argv[2];

// Check if movieId is provided
if (!movieId) {
    console.error('Please provide a Movie ID.');
    process.exit(1);
}

// Base URL for the Star Wars API
const baseUrl = 'https://swapi.dev/api/films/';

// Fetch and display characters
async function fetchCharacters(movieId) {
    try {
        // Fetch movie details
        const response = await axios.get(`${baseUrl}${movieId}/`);
        const movieData = response.data;

        // Get the list of character URLs
        const characterUrls = movieData.characters;

        // Fetch and display each character's name
        for (const url of characterUrls) {
            const characterResponse = await axios.get(url);
            console.log(characterResponse.data.name);
        }
    } catch (error) {
        console.error('Error fetching data:', error);
    }
}

// Call the function to fetch characters
fetchCharacters(movieId);
