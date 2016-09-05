 <!-- Start subscribe us -->
  <section id="subscribe">
    <div class="subscribe-overlay">
      <div class="container">
        <div class="row">
          <div class="col-md-12">
            <div class="subscribe-area">
              <h2 class="wow fadeInUp">Subscribe Newsletter</h2>
              <form action="" class="subscrib-form wow fadeInUp" data-wow-duration="0.5s" data-wow-delay="0.5s">
                <input type="text" placeholder="Enter Your E-mail..">
                <button class="subscribe-btn" type="submit">Submit</button>
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  </section>
  <!-- End subscribe us -->

  <!-- Start footer -->
  <footer id="footer">
    <div class="container">
      <div class="row">
        <div class="col-md-6 col-sm-6">
          <div class="footer-left">
             <p>Copyright &copy; ChiefObiTV 2016</p>
          </div>
        </div>
        <div class="col-md-6 col-sm-6">
          <div class="footer-right">
            
          </div>
        </div>
      </div>
    </div>
  </footer>
  <!-- End footer -->

  <!-- jQuery library -->
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>    
  <!-- Include all compiled plugins (below), or include individual files as needed -->
  <!-- Bootstrap -->
  <script src="assets/js/bootstrap.js"></script>
  <!-- Slick Slider -->
  <script type="text/javascript" src="assets/js/slick.js"></script>    
  <!-- mixit slider -->
  <script type="text/javascript" src="assets/js/jquery.mixitup.js"></script>
  <!-- Add fancyBox -->        
  <script type="text/javascript" src="assets/js/jquery.fancybox.pack.js"></script>
 <!-- counter -->
  <script src="assets/js/waypoints.js"></script>
  <script src="assets/js/jquery.counterup.js"></script>
  <!-- Wow animation -->
  <script type="text/javascript" src="assets/js/wow.js"></script> 
  <!-- progress bar   -->
  <script type="text/javascript" src="assets/js/bootstrap-progressbar.js"></script>  
<script src="assets/js/zabuto_calendar.min.js"></script>
 <!-- Custom JS   -->
 <script src="assets/js/scripts.js"></script>
  
 <script>
    $('.carousel').carousel({
        interval: 5000 //changes the speed
    })
</script>
<script type="application/javascript">
    $(document).ready(function () {
        $("#my-calendar").zabuto_calendar({
            cell_border: true,
            show_previous: false,
            weekstartson: 0,
            today: true,
            nav_icon: {
                prev: '<i class="fa fa-chevron-circle-left"></i>',
                next: '<i class="fa fa-chevron-circle-right"></i>'
      },
            ajax: {
          url: "show_data.php",
          modal: true
      }
        });
    });
</script>
  <!-- Custom js -->
  <script type="text/javascript" src="assets/js/custom.js"></script>
  
  </body>
</html>