$(document).on('click', '#submitButton', function(){
  if(check_form_fields()){
  $(".contact-area-left").fadeOut(100);
  var name = $("#name").val();
  var phone = $("#phone").val();
  var date = $("#date").val();
  var location = $("#location").val();
  var note = $("#notes").val();
  var email = $("#email").val();
  var events = $("#event").val();
  var data = "name="+name+"&phone="+phone+"&date="+date+"&location="+location+"&notes="+note+"&email="+email+"&events="+events;
  $.ajax({
    method:"POST",
    url: "save_event.php",
    data: data,
    success: function(response){
        $("#confirmBooking").html(response);
    }
  });
  }

})

function check_form_fields(){
  var errors = 0;
  if($("#name").val() == ""){
  errors +=1;
  $("#name").css({
     borderColor: "red"
  });
  $("#name_warning").html("Please Provide A Name");
  }else{
  $("#name").css({
     borderColor: "green"
  });
  $("#name_warning").html("");
  }
  if($("#phone").val() ==""){
  errors +=1;
  $("#phone").css({
      borderColor: "red"
  });
  $("#phone_warning").html("Please Provide A Phone Number");
  }else{
   $("#phone").css({
      borderColor: "green"
  });
  $("#phone_warning").html("");
  }
  if($("#email").val()==""){
  errors +=1;
  $("#email").css({
      borderColor: "red"
  });
  $("#email_warning").html("Please Provide An Email Address");
  }else{
    $("#email").css({
      borderColor: "green"
  });
  $("#email_warning").html("");
  }

  if($("#event").val()==""){
  errors +=1;
  $("#event").css({
      borderColor: "red"
  });
  $("#event_warning").html("Please Enter A Title For The Event");
  }else{
   $("#event").css({
      borderColor: "green"
  });
  $("#event_warning").html("");
  }
  if($("#location").val() == ""){
  errors +=1;
  $("#location").css({
      borderColor: "red"
  });
  $("#location_warning").html("Please Provide The Location Of The Event");
  }else{
   $("#location").css({
      borderColor: "green"
  });
  $("#location_warning").html("");
  }
  if($("#date").val() == ""){
  errors +=1;
  $("#date").css({
      borderColor: "red"
  });
  $("#date_warning").html("Please Enter Date Of Event");
  }else{
   $("#date").css({
      borderColor: "green"
  });
  $("#date_warning").html("");
  }
  if(errors > 0){
  return false;
  }
  return true;

}
