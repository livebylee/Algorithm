function solution(name, yearning, photo) {
    const nameToYearning = name.reduce((acc, curr, idx) => {
        acc[curr] = yearning[idx];
        return acc;
    }, new Object);
    
    return photo.map(
        (nameArr) => nameArr.map(now => nameToYearning[now])
            .filter(value => value !== undefined)
            .reduce((acc, curr) => acc + curr, 0)
    )
}
