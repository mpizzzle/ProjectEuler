package main

import (
  "fmt"
  "io/ioutil"
  "strings"
  "strconv"
)

type Node struct {
  cost int
  distance int
  included bool
}

func dijkstra(matrix [][]Node) int {
  for count := 0; count < (80 * 80) - 1; count++ {
    min := 1<<31 - 1
    var min_x int
    var min_y int

    for x := 0; x < 80; x++ {
      for y := 0; y < 80; y++ {
        if matrix[x][y].included == false && matrix[x][y].distance <= min {
          min = matrix[x][y].distance
          min_x = x
          min_y = y
        }
      }
    }

    matrix[min_x][min_y].included = true

    for x := 0; x < 80; x++ {
      for y := 0; y < 80; y++ {
        if x + 1 < 80 {
          if (!matrix[x + 1][y].included) && matrix[x][y].distance != 1<<31 - 1 && matrix[x][y].distance + matrix[x + 1][y].cost < matrix[x + 1][y].distance {
            matrix[x + 1][y].distance = matrix[x][y].distance + matrix[x + 1][y].cost
          }
        }


        if y + 1 < 80 {
          if (!matrix[x][y + 1].included) && matrix[x][y].distance != 1<<31 - 1 && matrix[x][y].distance + matrix[x][y + 1].cost < matrix[x][y + 1].distance {
            matrix[x][y + 1].distance = matrix[x][y].distance + matrix[x][y + 1].cost
          }
        }

        if y - 1 >= 0 {
          if (!matrix[x][y - 1].included) && matrix[x][y].distance != 1<<31 - 1 && matrix[x][y].distance + matrix[x][y - 1].cost < matrix[x][y - 1].distance {
            matrix[x][y - 1].distance = matrix[x][y].distance + matrix[x][y - 1].cost
          }
        }
      }
    }
  }

  min := 1<<31 - 1

  for y := 0; y < 80; y++ {
    if matrix[79][y].distance <= min {
      min = matrix[79][y].distance
    }

    if matrix[79][y].distance == 1<<31 - 1 {
      panic("!")
    }
  }

  return min
}

func main() {
  dat, _ := ioutil.ReadFile("./files/matrix_82.txt")

  min :=1<<31 - 1

  for y := 0; y < 80; y++ {
    var matrix [][]Node

    for _, r := range strings.Split(string(dat), "\n") {
      var int_row []Node

      for _, r2 := range strings.Split(r, ",") {
        var n Node
        cost, _ := strconv.Atoi(r2)
        n.cost = cost
        n.distance = 1<<31 - 1
        n.included = false
        int_row = append(int_row, n)
      }

      matrix = append(matrix, int_row)
    }

    matrix[0][y].distance = matrix[0][y].cost
    if y > 0 {
      fmt.Println(matrix[0][y - 1].distance)
    }

    potential_min := dijkstra(matrix)

    fmt.Println(potential_min)

    if potential_min <= min {
      min = potential_min
    }
  }

  fmt.Println(min)
}
