
program d1p1
  implicit none
  integer, dimension(200) :: data
  integer :: i, j

  do i=1, 200
    read(*,"(I12.1)") data(i)
  end do

  do i=1, 200
    do j=1, 200

      ! We don't count adding with ourselves
      if (i == j) then
        continue
      end if

      if (data(i)+data(j)==2020) then
        write(*,*) (data(i)*data(j))
        exit
      end if

    end do
  end do

end program d1p1

