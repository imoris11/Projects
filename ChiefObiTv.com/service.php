<?php 
require_once("header.php");
require_once("db.php");
?>  
  <!-- Start Service -->
  <section id="service">
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <div class="title-area">
            <h2 class="title">Our Services</h2>
            <span class="line"></span>
          </div>
        </div>
        <div class="col-md-12">
          <div class="service-content">
            <div class="row">
              <!-- Start single service -->
                <?php
                $query = "SELECT * FROM services";
                $services = mysqli_query($connection, $query);
                while($service = mysqli_fetch_assoc($services)){
                    ?>
            <div class="col-md-4 col-sm-6">
                <div class="single-service wow zoomIn">
                  <h4 class="service-title"><?php echo $service['title'] ?></h4>
                  <p><?php echo $service['detail']?></p>
                </div>
              </div>
                <?
                }
                ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
  <!-- End Service -->
 <?php 
require_once("footer.php")
    ?>